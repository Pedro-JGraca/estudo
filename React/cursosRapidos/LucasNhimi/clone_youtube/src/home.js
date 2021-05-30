
import React from 'react';

import { 
   makeStyles,AppBar,Toolbar,IconButton,
   Button, Drawer, List, ListItem, ListItemIcon, 
   ListItemText, Divider, Box, Typography, Grid, Hidden, useTheme, Switch
  } from "@material-ui/core";

import {
  Menu,AccountCircle,VideoCall,Apps,MoreVert,
  Whatshot,Subscriptions,VideoLibrary,History
} from '@material-ui/icons';

import HomeIcon from '@material-ui/icons/Home';

const videos = [
  {
    id: 1,
    title:
      'FEED DO USUÁRIO | Criando uma Rede Social com React.js e .NET Core #29',
    channel: 'Lucas Nhimi',
    views: '11 mi de visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb1.png',
  },
  {
    id: 2,
    title:
      'COMO MELHORAR SEU CODIGO JAVASCRIPT (ESLINT + PRETTIER + EDITORCONFIG) | Dicas e Truques #02',
    channel: 'Lucas Nhimi',
    views: '957 mil visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb2.png',
  },
  {
    id: 3,
    title:
      'CONTEXT API NO EDITOR DE POST | Criando uma Rede Social com React.js e .NET Core #27',
    channel: 'Lucas Nhimi',
    views: '106 mil visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb3.png',
  },
  {
    id: 4,
    title:
      'CONTEXT API NO EDITOR DE POST | Criando uma Rede Social com React.js e .NET Core #27',
    channel: 'Lucas Nhimi',
    views: '5,6 mi de visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb4.png',
  },
  {
    id: 5,
    title:
      'EDITOR DE POST COM MARKDOWN 2 | Criando uma Rede Social com React.js e .NET Core #26',
    channel: 'Lucas Nhimi',
    views: '2,2 mi de visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb5.png',
  },
  {
    id: 6,
    title: 'COMO MIGRAR PARA REACT HOOKS | Dicas e Truques #01',
    channel: 'Lucas Nhimi',
    views: '233 mil visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb6.png',
  },
  {
    id: 7,
    title:
      'PRÉ-REQUISITOS | Criando uma Rede Social com React.js e .NET Core #01',
    channel: 'Lucas Nhimi',
    views: '118 mil visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb7.png',
  },
  {
    id: 8,
    title:
      'GIT E GITHUB | Criando uma Rede Social com React.js e .NET Core #04',
    channel: 'Lucas Nhimi',
    views: '1,9 mi de visualizações',
    date: 'há 1 semana',
    avatar: '/images/avatar.jpeg',
    thumb: '/images/thumb8.png',
  },
];

const useStyles = makeStyles((theme) => ({
  root: {
      height: '100vh',
      backgroundColor: theme.palette.background.dark,
    },
  AppBar: {
    boxShadow: 'none',
    zIndex: theme.zIndex.drawer + 1,
  },
  logo: {
    height: 25,
  },
  drawer: {
    width: 240,
    flexShrink: 0,
  },
  drawerPaper: {
    width: 240,
    borderRight: 'none',
  },
  grow: {
    flexGrow: 1,
  },
  menuIcon: {
    paddingRight: theme.spacing(5),
    paddingLeft: theme.spacing(6),
  },

  icons: {
    paddingRight: theme.spacing(5), // 8px*5
  },
  listItemText: {
    fontSize: 14,
  },
  listItem: {
    paddingTop: 4,
    paddingBottom: 4,
  }


  }));

const Home = ({darkMode, setDarkMode}) => {
    const classes = useStyles();
    const theme = useTheme();

    return (
    <div className={classes.root}>
      <AppBar color='inherit' className = {classes.AppBar}>
        <Toolbar>
          <IconButton
            edge='start'
            aria-label="menu"
            className ={classes.menuIcon}
          >
            <Menu />
          </IconButton>

          <img src={theme.palette.type === 'dark' ? "/images/branco.png" : "/images/preto.png"} alt="logo" className={classes.logo} />
          
          <div className={classes.grow} />

          <Switch 
            value={darkMode}
            className={classes.icons}
            onChange={() => setDarkMode(!darkMode)} 
          />

          <IconButton className ={classes.icons}>
            <VideoCall />
          </IconButton>
          <IconButton className ={classes.icons}>
            <Apps />
          </IconButton>
          <IconButton  className ={classes.icons}>
            <MoreVert />
          </IconButton>

          <Button 
            variant="outlined"
            color='secondary'
            startIcon={<AccountCircle />}
          >
            fazer login
          </Button>
        </Toolbar>
      </AppBar>
      
      <Box display='flex' >

        <Hidden mdDown>

          <Drawer
            className={classes.drawer}
            variant='permanent'
            classes={{
              paper: classes.drawerPaper,
            }}
          >
            <Toolbar />
            <div className={classes.drawerContainer}>
              <List>

                <ListItem button classes = {{root: classes.listItem}}>
                    <ListItemIcon>{<HomeIcon />}</ListItemIcon>
                    <ListItemText
                      classes={{
                        primary: classes.listItemText,
                      }}
                      primary={'Inicio'} 
                    />
                </ListItem>

                <ListItem button classes = {{root: classes.listItem}} >
                    <ListItemIcon>{<Whatshot />}</ListItemIcon>
                    <ListItemText
                      classes={{
                        primary: classes.listItemText,
                      }}
                      primary={'Em Alta'} 
                    />
                </ListItem>

                <ListItem button classes = {{root: classes.listItem}}>
                    <ListItemIcon>{<Subscriptions />}</ListItemIcon>
                    <ListItemText
                      classes={{
                        primary: classes.listItemText,
                      }}
                      primary={'Inscrições'} 
                    />
                </ListItem>
              </List>

              <Divider />

              <List>

                <ListItem button classes = {{root: classes.listItem}}>
                    <ListItemIcon>
                      <VideoLibrary />
                    </ListItemIcon>
                    <ListItemText
                      classes={{
                        primary: classes.listItemText,
                      }}
                      primary={'Biblioteca'} 
                    />
                </ListItem>

                <ListItem button classes = {{root: classes.listItem}} >
                    <ListItemIcon>
                      <History />
                    </ListItemIcon>
                    <ListItemText
                      classes={{
                        primary: classes.listItemText,
                      }}
                      primary={'Histórico'} 
                    />
                </ListItem>
              </List>

              <Divider />
                <Box p={7}>
                  <Typography variant='body2'>
                    Faça login para curtir vídeos, comentar e se inscrever
                  </Typography>
                <Box mt={2}>
                    <Button
                      variant="outlined"
                      color='secondary'
                      startIcon={<AccountCircle />}
                      >
                        fazer login
                    </Button>

                  </Box>


                </Box>

                <Divider />


            </div>
          </Drawer>

        </Hidden>

        <Box p={8}>
          <Toolbar />
          <Typography
            variant='h5'
            color='textPrimary'
            style={{ fontWeight: 600 }}
          >
            Recomendados
          </Typography>
          <Grid container spacing={4}>
            {
              videos.map((item,index) => (
              
                <Grid item lg={3} md={4} sm={6} xs={12}>
                  <Box>
                    <img
                      style={{ width:'100%'}}
                      alt={item.tilte}
                      src={item.thumb}
                    />
                    <Box>
                      <Typography
                      gutterBottom
                        variant='body1'
                        color='textPrimary'
                        style={{ fontWeight: 600 }}
                      >
                        {item.title}
                      </Typography>
                      <Typography
                        variant='body2'
                        color='textSecondary'
                        display='block'
                      >
                        {item.channel}
                      </Typography>
                      <Typography
                        variant='body2'
                        color='textSecondary'
                      >
                        {`${item.views} x ${item.date}`}
                      </Typography>
                    </Box>
                  </Box>
                </Grid>

              ))
            }
          </Grid>

        </Box>
      
      </Box>
    </div>
    );
}
 
export default Home;