import React, { useState } from 'react';
import {createMuiTheme, ThemeProvider } from "@material-ui/core";

import Home from './home'
import { dark } from '@material-ui/core/styles/createPalette';

function App() {

  const [darkMode, setDarkMode] = useState(false);

  const theme = createMuiTheme({
    spacing: 4,
    palette: {
      type: darkMode ? 'dark': 'light', 

      primary: {
        main: '#f44336',
      },
      secondary: {
        main: '#3EA6FF',
      },
      background:{
        default: darkMode ? '#232323' : '#FFF',
        dark: darkMode ? '#181818' : '#f4f6f8',
        paper: darkMode ? '#232323' : '#FFF',
      }
    }

  })

  return <div>
    <ThemeProvider theme={theme}>
      <Home darkMode={darkMode} setDarkMode={setDarkMode} />
    </ThemeProvider>
  </div>;
}

export default App;
