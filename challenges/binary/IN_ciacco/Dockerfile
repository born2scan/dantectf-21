FROM alpine as builder

RUN apk add --no-cache build-base

WORKDIR /build

COPY src/ .

RUN gcc -Wall -static -s chall-server.c checks.c -o chall-server

# ---

FROM alpine:edge

RUN apk --no-cache add socat

COPY --from=builder /build/chall-server /chall-server

ENTRYPOINT ["socat", "-s", "-T30", "TCP4-LISTEN:1337,fork,reuseaddr", "EXEC:/chall-server,setsid"]

EXPOSE 1337
