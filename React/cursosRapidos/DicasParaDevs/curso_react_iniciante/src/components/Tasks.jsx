import React from 'react';

import Task from './Task';

const Tasks = ( {tasks, handleTaskClick,dropTaskClick} ) => {

    return (
    <div>
        {tasks.map((task) => (
            <Task
                key = {task.id}
                task = {task} 
                handleTaskClick={handleTaskClick} 
                dropTaskClick = {dropTaskClick} 
            />
        ))}
    </div>
    )
}

export default Tasks