
import React from 'react';
import MenuIcon from '@material-ui/icons/Menu';
import { makeStyles,AppBar,Toolbar,IconButton, Button } from "@material-ui/core";
import AccountCircleIcon from '@material-ui/icons/AccountCircle';
import VideoCallIcon from '@material-ui/icons/VideoCall';
import AppsIcon from '@material-ui/icons/Apps';
import MoreVertIcon from '@material-ui/icons/MoreVert';

const Home = () => {
    const useStyles = makeStyles((theme) => ({
    root: {
        height: '100vh'
      },
    AppBar: {
      boxShadow: 'none'
    },
    grow: {
      flexGrow: 1
    },
    MenuIcon: {
      paddingRight: theme.spacing(4),
      paddingLeft: theme.spacing(0)
    },
    icons: {
      paddingRight: theme.spacing(0) // 8px*0
    },
    login: {
      border: "2px solid",
      height: "10%",
      width: "9%"
    }
    }));
    
    const classes = useStyles()

    return (
    <div className={classes.root}>
      <AppBar color='inherit' className = {classes.AppBar}>
        <Toolbar>
          <IconButton
            color="inherit"
            aria-label="menu"
            className ={classes.MenuIcon}
          >
            <MenuIcon />
          </IconButton>
          
          <div className={classes.grow} />

          <IconButton color="inherit" className ={classes.icons}>
            <VideoCallIcon />
          </IconButton>
          <IconButton color="inherit" className ={classes.icons}>
            <AppsIcon />
          </IconButton>
          <IconButton color="inherit" className ={classes.icons}>
            <MoreVertIcon />
          </IconButton>

          <Button 
            variant="outlined"
            color='secondary'
            className ={classes.login}
            startIcon={<AccountCircleIcon />}
          >
            fazer login
          </Button>
        </Toolbar>
      </AppBar>
    </div>
    );
}
 
export default Home;