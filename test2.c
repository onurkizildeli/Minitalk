#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    const char *unicodeStr = "Merhaba, dünya! Unicode karakterler: öğünçı";

    // Dosya tanımlayıcısı 1, standart çıkışı temsil eder
    int fd = 1;

    // write işlemini kullanarak Unicode metni yaz
    ssize_t bytesWritten = write(fd, unicodeStr, strlen(unicodeStr));

    if (bytesWritten == -1) {
        perror("write");
        return 1;
    }

    return 0;
}