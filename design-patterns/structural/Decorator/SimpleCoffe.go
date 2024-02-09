package main

type SimpleCoffee struct {
	client string
}

// GetPrice / simple coffee price
func (sc *SimpleCoffee) GetPrice() float64 {
	return 10
}

func (sc *SimpleCoffee) GetClient() string {
	return sc.client
}

func NewSimpleCoffee(client string) *SimpleCoffee {
	return &SimpleCoffee{client}
}
