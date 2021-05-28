import React, { useEffect, useState } from 'react'
import {v4 as uuidv4} from 'uuid'
import {BrowserRouter as Router, Route} from 'react-router-dom'
import axios from 'axios'

import Tasks from './components/Tasks'
import  './App.css'
import AddTask from './components/AddTask';
import TaskDetails from './components/TaskDetails';


const App = () => {
  //let message = 'Hello World! 2';
  const [tasks, setTasks] = useState([
    /*{
      id: '1',
      title: 'Estudar Programacao',
      completed: false,
    },
    {
      id: '2',
      title: 'ler livros',
      completed: true,
    }*/
  ]);

  useEffect(() => {
    const fetchTasks = async() => {
      const {data} = await axios.get(
        'https://jsonplaceholder.cypress.io/todos?_limit=10'
      )
      setTasks(data)
    }
    fetchTasks();
  }, [])

  const handleTaskAddition = (taskTitle) => {
    const newTask = [ ... tasks,{
      id: uuidv4(),
      title: taskTitle,
      completed: false
    }]
    setTasks(newTask)
  }

  const handleTaskClick = (taskId) => {
    const newTasks = tasks.map(task => {
      if (task.id === taskId) return { ...task, completed: !task.completed}
      return task;
    })
    setTasks(newTasks)
  }

  const dropTaskClick = (taskId) => {
    const newTasks = tasks.filter(task => task.id !== taskId)

    setTasks(newTasks)
  }

  


  return (
    <Router>
      <div className = 'container'>
        <h1 style = {{color:"#eee"}}>Minhas Tarefas</h1>
        <Route path="/" exact render={() => (
          <>
            <AddTask handleTaskAddition = {handleTaskAddition} />
            <Tasks tasks = {tasks} handleTaskClick={handleTaskClick} dropTaskClick={dropTaskClick}/>
          </>
        )} />
        <Route path="/:taskTitle" exact component={TaskDetails} />
      </div>
    </Router>
  ); 
}

export default App;