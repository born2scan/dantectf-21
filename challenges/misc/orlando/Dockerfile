FROM golang:alpine as builder

RUN apk add --no-cache binutils

WORKDIR /build

COPY . .

RUN CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -a -ldflags '-extldflags "-w -s -static"' -o orlando . && \
    strip ./orlando

# ---

FROM scratch

COPY --from=builder /build/orlando /orlando

ENTRYPOINT ["/orlando"]

EXPOSE 1337