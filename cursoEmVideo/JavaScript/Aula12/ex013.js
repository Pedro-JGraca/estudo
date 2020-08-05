var agora = new Date();

var diaSem = agora.getDay();
/*
    Domingo é 0
    Segunda é 1
    Terça   é 2
    Quarta  é 3
    QUinta  é 4
    Sexta   é 5
    Sabado  é 6
*/


switch (diaSem) {
    case 0:
        console.log('Domingo'); 
        break;
    
    case 1:
        console.log('Segunda');
        break;
    
    case 2:
        console.log('Terça'); 
        break;
    
    case 3:
        console.log('Quarta'); 
        break;

    case 4:
        console.log('Quinta'); 
        break;

    case 5:
        console.log('Sexta'); 
        break;    

    case 6:
        console.log('Sabado'); 
        break;

    default:
        console.log('Nao sei');
        break;
}