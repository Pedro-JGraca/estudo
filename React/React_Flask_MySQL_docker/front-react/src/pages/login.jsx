import React, { useState } from 'react';
import './login.css'
import Button from "../componentes/Button"
import { useHistory } from 'react-router-dom';

//const Login = ({API-CADASTRO-USUARIO}) => {
const Login = ({loginForDashBorder}) => {
    const [inputDataUser, setInputDataUser] = useState('');
    const [inputDataPass, setInputDataPass] = useState('');

    const history = useHistory();

    const handleInputUser = (e) => {
        setInputDataUser(e.target.value)
    }

    const handleInputPass = (e) => {
        setInputDataPass(e.target.value)
    }

    const handleClickLogin = () => {
        
        //ele verifca se pode entrar, se sim, retorna True + JWT
        //se não escreve por 5 segundos: Senha ou Usuario Incorretos!
        /*api
            [login, jwt]  = verificarCadastroUusuario(inputDataUser,inputDataPass)
        */
        const login = true
        const jwt = 0
        if (login === true){
            history.push('/DashBoard')
            //sempre que usar uma API tenho que pegar o jwt guardado, tenho que pensar como vou fazer isso depois que terminar todas as partes do front, que ai vou entender qual vai ser a comunicação do front com o back
        }
        else{

            //popUP Erro
        }
        
        
    }

    const handleClickRegister = () => {
        history.push('/register')
            
        
    }


    return (
        <div className='login'>
            <div className='register'>
                <Button onClick={handleClickRegister}>Registrar</Button>
            </div>
                <br />
            <div>
                <label htmlfor="username" className='usernameImage'>Username:</label>
                <br />
                <input
                    onChange={handleInputUser}
                    value = {inputDataUser} 
                    className='username'
                    type="text"     
                />
            </div>
                <br />
            <div>
                <label htmlFor="pass" className='passImage'>Password:</label>
                <br />
                <input
                    onChange={handleInputPass}
                    value = {inputDataPass} 
                    className='password'
                    type='password'  
                />
            </div>
                <br />
            <div className='input'>
                <Button onClick={handleClickLogin}>Entrar</Button>
            </div>
            
        </div>
    );
}
 
export default Login;