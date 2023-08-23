var campo = document.querySelector("#campo");
var salvar = document.querySelector("#salvar");

salvar.onclick = function() {
    var el = document.createElement('p');
    el.textContent = campo.value;

    conteudo.appendChild(el);
    campo.value = "";
}