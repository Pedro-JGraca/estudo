import React from 'react';
import {CgClose,CgInfo} from 'react-icons/cg';
import {useHistory} from 'react-router-dom'

import "./task.css"

const Task = ({task,handleTaskClick,dropTaskClick}) => {
    const history = useHistory();

    const handleTaskDetailsClick = () => {
        history.push(`/${task.title}`)
    }

    return (
        <div className='task-container' style={task.completed ? {borderLeft: '6px solid chartreuse'} : {}}>
        
            <div className='task-title' onClick={() => handleTaskClick(task.id)}>
                {task.title}
            </div>


            <div className='see-task-details' onClick = {() => handleTaskDetailsClick()}>
                <CgInfo />
            </div>

            <div className='close-button' onClick = {() => dropTaskClick(task.id)}>
                <CgClose />
            </div>


        </div>
    );
}
 
export default Task;