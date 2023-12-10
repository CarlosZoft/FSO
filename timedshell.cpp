#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <cerrno>
#include <cstring>
#include <iomanip>

double calcTime(struct timeval start, struct timeval end)
{
    return (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);
}

int main()
{
    int err = 0;
    bool isFirst = true;
    struct timeval total_start, total_end, start;

    char PATH[256], arg[256];
    while (std::cin >> PATH >> arg)
    {
        if (isFirst)
        {
            gettimeofday(&total_start, nullptr);
            isFirst = false;
        }
        gettimeofday(&start, nullptr);

        std::cout.flush();
        int pid = fork();

        if (pid == 0)
        {
            execl(PATH, PATH, arg, nullptr);

            char *output = strerror(errno);
            if (std::strcmp(output, "Success") != 0)
            {
                std::cout << "> Erro: " << output << std::endl;
                std::cout.flush();
                err = errno;
                std::fclose(stdin);
                std::exit(errno);
            }
        }
        if (waitpid(pid, &err, WUNTRACED))
        {
            err = WEXITSTATUS(err);
            struct timeval end;
            gettimeofday(&end, nullptr);
            std::cout << "> Demorou " << std::fixed << std::setprecision(1) << calcTime(start, end) << " segundos, retornou " << err << std::endl;
            std::cout.flush();
        }
    }
    gettimeofday(&total_end, nullptr);

    std::cout << ">> O tempo total foi de " << std::fixed << std::setprecision(1) << calcTime(total_start, total_end) << " segundos" << std::endl;
    std::cout.flush();
    std::exit(0);
}
