import React from 'react';
import { useParams, useHistory } from 'react-router-dom';

import Buttom from "./Button"
import "./TaskDetails.css"

const TaksDetais = () => {
    const params = useParams();

    const history = useHistory();

    const voltarInicial = () => {
        history.goBack();
    }

    return ( 
        <div>
            <div className='back-button-container' onClick={() => voltarInicial()}>
            <Buttom>Voltar</Buttom>
            </div>
            
            <div className='task-details-container'>
                <h2>{params.taskTitle}</h2>
                <p>
                    QUALQUER TEXTO
                </p>
            </div>
        </div>

     );
}
 
export default TaksDetais;