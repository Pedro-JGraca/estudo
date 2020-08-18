
var inicio =window.document.getElementById("inicio"), fim = window.document.getElementById("fim"), passo = window.document.getElementById("passo");

var res = window.document.getElementById('res');

function disparar () {
    if (!inicio.value) {//verifica se inicio possui algum valor
        res.style.textAlign = "center";
        res.innerText = "Inicio Precisa de valor!";
    }

    else if (!fim.value) {//verifica se fim possui algum valor
        res.style.textAlign = "center";
        res.innerText = "Fim Precisa de valor!";
    }

    else if (!passo.value) {//verifica se passo possui algum valor
        res.style.textAlign = "center";
        res.innerText = "Passo Precisa de valor!";
    }

    else {//entra se todos tem valores
        let Inicio= Number(inicio.value);
        let Fim = Number(fim.value);
        let Passo = Number(passo.value);
            
        //verifica se os valores de Inicio, Fim e Passo são válidos
        if (Passo==0) {//verifica se passo é igual a zero
            res.style.textAlign = "center";
            res.innerText ="Passo precisa ser diverente de zero";
        }
        else if (Fim==Inicio) { //verifica se Inicio e Fim são Iguais
            res.style.textAlign = "center";
            res.innerText ="Inicio e Fim precisam ser distintos";
        }
        else if ((Inicio<Fim)&&(Passo<0)) { //Se Inicio < Fim e Passo < 0
            res.style.textAlign = "center";
            res.innerText ="Nesse Caso Passo precisa ser um valor positivo";
        }
        else if ((Inicio>Fim)&&(Passo>0)) { //se Inicio > Fim e Passo >0
            res.style.textAlign = "center";
            res.innerText ="Nesse Caso Passo precisa ser um valor negativo";
        }

        else if (((Inicio + Passo + Fim)>500)||((Inicio+Passo+Fim)<-500)){
            //valores muito altos ou muito baixos
            res.style.textAlign = "center";
            res.innerText ="Estorou os valores!";
        }

        else {//se todos os valores testados são validos
            res.innerText ="";
        
            res.style.textAlign = "justify";
            let c = Inicio;
            if (Inicio<Fim) { //for crescente
                for (;c<=Fim;c+=Passo) {
                    res.innerText += " " + c.toString();
                    res.innerText += " \u{1F449}";

                }
                res.innerText += " \u{1F3C1}";
            }
            else if (Inicio>Fim) {//for descrescente
                for (;c>=Fim;c+=Passo) {
                    res.innerText += " " + c.toString();
                    res.innerText += " \u{1F449}";
                }
                res.innerText += " \u{1F3C1}";
            }
            else {
                res.style.textAlign = "center";
                res.innerText =" Caso não Previsto!";
            }


        }
    }
        
}

