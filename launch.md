## О запуске

```git clone``` \
```cd src```

Есть возможность запустить тесты с использованием Docker контейнера (предполагается установленный Docker)

```docker pull alpine:3.20``` \
```docker build -t matrix-alpine .``` \
```docker run --rm matrix-alpine``` \

Также можно проверить стиль

```cd ../materials/build``` \
```sh run.sh```