#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int main() {
    int serial_port = open("./entrada", O_WRONLY);

    if (serial_port < 0) {
        printf("Erro ao abrir o dispositivo: %s\n", strerror(errno));
        return 1;
    }
    
    struct termios tty;
    if (tcgetattr(serial_port, &tty) != 0) {
        printf("Erro ao obter os atributos do terminal: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }
    
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);
    
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHONL | ISIG);
    
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;
    
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 0;
    
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Erro ao definir os atributos do terminal: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }
    
    unsigned char msg[256] = "mensagem do terminal\n";
    ssize_t bytes_written = write(serial_port, msg, sizeof(msg));
    
    if (bytes_written < 0) {
        printf("Erro ao escrever no dispositivo: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }
    
    printf("Mensagem enviada com sucesso!\n");
    
    close(serial_port);
    
    return 0;
    //socat PTY,link=./entrada,raw,echo=0 PTY,link=./saida,raw,echo=0
}
