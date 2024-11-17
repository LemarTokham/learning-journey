import React, { useState } from "react";

function TaskList() {
    // initialising state for our tasks
    const [tasks, setTasks] = useState([
        { id: 1, text: "Learn React Basics", completed: false },
        { id: 2, text: "Build Task Dashboard", completed: false },
    ]);

    // handling task toggling
    const toggleTask = (taskId) => {
        setTasks(tasks.map(task =>
            task.id === taskId
            ? {...task, completed: !task.completed}
            :task
        ))
    }

    return (
        <div className="task-list">
            <h2>My Tasks</h2>
            <ul>
                {tasks.map(task => (
                    <li key={task.id}
                    onClick={() => toggleTask(task.id)}
                        style={{
                            textDecoration: task.completed ? 'line-through' : 'none',
                            cursor: 'pointer'
                        }}
                        >
                        {task.text}
                    </li>
                ))}
            </ul>
        </div>
    );
}


export default TaskList;