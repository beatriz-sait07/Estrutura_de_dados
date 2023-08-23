var link = document.querySelector('a#add');
var conteudo = document.querySelector('div.conteudo');

link.onclick = function() {
    var el = document.createElement('p');
    el.textContent = Math.random();

    conteudo.appendChild(el);
}