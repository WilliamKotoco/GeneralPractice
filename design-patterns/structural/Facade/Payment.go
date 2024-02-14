package main

type Payment struct {
	price float64
}

func (p *Payment) getPrice() float64 {
	return p.price
}

func (p *Payment) process() error {
	return nil
}
