package main

import (
	"bufio"
	"log"
	"net"
	"os"
	"strings"
)

const (
	connHost = "0.0.0.0"
	connPort = "1337"
	connType = "tcp"
)

func main() {
	log.SetOutput(os.Stdout)
	log.Println("Listening on " + connHost + ":" + connPort + ":" + connType)

	l, err := net.Listen(connType, connHost+":"+connPort)
	if err != nil {
		log.Println("Error listening:", err.Error())
		os.Exit(1)
	}
	//goland:noinspection GoUnhandledErrorResult
	defer l.Close()

	for {
		conn, err := l.Accept()
		if err != nil {
			log.Println("Error receiving connection:", err.Error())
			continue
		}
		log.Println("Client connected:", conn.RemoteAddr().String())

		go handleConn(conn)
	}
}

//goland:noinspection GoUnhandledErrorResult
func handleConn(conn net.Conn) {
	quotes := GetQuotes()
	for _, quote := range quotes {
		conn.Write([]byte("\n" + quote[0] + "\n\n-> "))
		buffer, err := bufio.NewReader(conn).ReadBytes('\n')
		if err != nil {
			log.Println("Client left:", conn.RemoteAddr().String())
			conn.Close()
			return
		}

		reply := strings.Trim(string(buffer), "\n")
		log.Println(conn.RemoteAddr().String(), "said:", reply)
		if reply != quote[1] {
			conn.Write([]byte("\n>:(\n"))
			conn.Close()
			return
		}
	}
	conn.Write([]byte("\nDANTE{3cc0_l4_f13r4_c0n_l4_c0d4_46uzz4}\n"))
	conn.Close()
}
