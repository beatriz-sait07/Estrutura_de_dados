#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int main() {
    int serial_port = open("./saida", O_RDONLY);
    
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
    
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHONL | ISIG);
    
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);

    
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Erro ao definir os atributos do terminal: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }
    
    char read_buf[256];
    memset(read_buf, '\0', sizeof(read_buf));
    
    ssize_t num_bytes = read(serial_port, read_buf, sizeof(read_buf) - 1);
    
    if (num_bytes < 0) {
        printf("Erro ao ler do dispositivo: %s\n", strerror(errno));
        close(serial_port);
        return 1;
    }
    
    //read_buf[num_bytes] = '\0';
    printf("Mensagem recebida: %s\n", read_buf);
    
    
    close(serial_port);
    
    return 0;
}
