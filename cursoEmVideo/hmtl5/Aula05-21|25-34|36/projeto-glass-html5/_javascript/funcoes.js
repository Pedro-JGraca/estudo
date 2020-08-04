function mudaFoto (id,foto) {
    document.getElementById(id).src =  foto;
}

function calc_total() {
    var valor=1500;
    document.getElementById('cTot').value = parseInt(document.getElementById('cQtd').value)*valor;
}


