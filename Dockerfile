FROM gcc:latest
WORKDIR /Projeto-c
COPY main.c /Projeto-c
RUN gcc -o main main.c
CMD ["./main"]