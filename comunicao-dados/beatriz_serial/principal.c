#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
int main () {
    int serial_port = open("/dev/pts/0", O_RDWR); //o_rdwr abre o arquivo para leitura e escrita
    struct termios tty;
    
    if (tcgetattr(serial_port, &tty) != 0) { //chamada para obter os atributos atuais do terminal associado ao descritor de arquivo
        printf("Error %i from tcgetattr: %s \n ", errno, strerror (errno)); //Se a função falhar, uma mensagem de erro é exibida, mostrando o número do erro e uma mensagem descritiva
        return 1 ;
    }
    tty.c_cflag &= ~PARENB; //define um unico bit de parada
    tty.c_cflag &= ~CSTOPB; //configura o numero de bits de parada
    tty.c_cflag &= ~CSIZE ; //limpa todos os bits que definem o tamanho dos caracteres
    tty.c_cflag |= CS8 ; //configura o numero de bits de dados
    tty.c_cflag &= ~CRTSCTS;  //desativa o controle de fluxo de hardware
    tty.c_cflag |= CREAD | CLOCAL; //habilita a recepção de caracteres e ignora os sinais de modem
    tty.c_lflag &= ~ICANON; //desativa o modo canônico
    tty.c_lflag &= ~ECHO; //desativa o eco
    tty.c_lflag &= ~ECHOE; //desativa o eco de caracteres apagados
    tty.c_lflag &= ~ECHONL; //desativa o eco de nova linha
    tty.c_lflag &= ~ISIG ; //desativa os sinais de entrada
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); //desativa o controle de fluxo de software
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); //desativa o tratamento de bytes de entrada especiais (não ASCII)
    tty.c_oflag &= ~OPOST; //desativa a pós-edição de saída de caracteres
    tty.c_oflag &= ~OPOST; //desativa a pós-edição de saída de caracteres
    tty.c_oflag &= ~ONLCR; //desativa a conversão de nova linha
    tty.c_cc [VTIME] = 10; //tempo de espera por dados (decimos de segundo)
    tty.c_cc [VMIN] = 0; //número mínimo de caracteres para ler
    cfsetispeed (&tty, B9600 ); //configura a velocidade de entrada
    cfsetospeed (&tty, B9600 ); //configura a velocidade de saída
    if ( tcsetattr (serial_port, TCSANOW, &tty) != 0 ) { //chamada para definir os atributos do terminal associado ao descritor de arquivo
        printf ( "Error %i from tcsetattr: %s \n ", errno, strerror(errno));
        return 1;
    }
    unsigned char msg [] = { 'H', 'e', 'l', 'l', 'o', '\r'} ;
    write (serial_port, msg, sizeof(msg));
    char read_buf[256];
    memset(&read_buf, '\0', sizeof (read_buf));
    int num_bytes = read (serial_port, &read_buf, sizeof(read_buf));
    if ( num_bytes < 0) {
        printf("Error reading:␣%s", strerror(errno));
        return 1 ;
    }
    printf( "Read %i bytes.Receivedmessage: %s", num_bytes, read_buf);
    close(serial_port);

    return 0 ;
}