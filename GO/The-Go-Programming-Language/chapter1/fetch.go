package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
)

func main() {
	for _, url := range os.Args[1:] {
		resp, err := http.Get(url) // resp gets the response and error gets the error, if any.

		if err != nil {
			fmt.Fprint(os.Stderr, "fetch: %v \n", err)
			os.Exit(1)
		}

		body, err := io.ReadAll(resp.Body)
		resp.Body.Close()

		if err != nil {
			fmt.Fprint(os.Stderr, "fetch: reading %s: %v ", url, err)
			os.Exit(1)
		}
		fmt.Println(string(body))
	}
}
