import React, { useEffect, useState } from 'react'
import {BrowserRouter as Router, Route} from 'react-router-dom'
import axios from 'axios'

import './App.css';

const App = () => {
  
  
  
  return (
    <Router>
      <h1> cabecalho</h1>
      <Route path='/' exact render ={() => (
        <>
          <div className="App">
          </div>
        </>
      )}/>

    </Router>

  );
}

/*
        <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
        </header>
*/

export default App;
