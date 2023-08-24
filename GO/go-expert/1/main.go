package main

/// package is the directory or it is the main. You cannot have a package under a directory
/// with a different name.
import "fmt"

func main() {
	/// it's possible to print the const a because the file "const.go"
	/// is on the same package that main.go
	fmt.Println(a)
}
