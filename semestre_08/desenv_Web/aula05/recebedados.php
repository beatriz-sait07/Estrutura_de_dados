<?php
    $nome = $_POST['txtNome']; //isso eh uma variavel global do php, mas entre os colchetes coloque os dados do html que deseja puxar
    $qtdFilhos = $_POST['txtQtdFilhos'];

    echo $nome . ' - ' . $qtdFilhos;
    
?>