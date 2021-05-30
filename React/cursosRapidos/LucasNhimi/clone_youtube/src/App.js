import React from 'react';
import { Button, createMuiTheme, ThemeProvider } from "@material-ui/core";

import Home from './home'

function App() {
  const theme = createMuiTheme({
    palette: {
      primary: {
        main: '#f44336',
      },
      secondary: {
        main: '#3f51b5',
      }
    }

  })

  return <div>
    <ThemeProvider theme={theme}>
      <Home />
    </ThemeProvider>
  </div>;
}

export default App;
