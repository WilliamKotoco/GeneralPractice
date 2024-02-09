package main

type CapuccinoDecorator struct {
	baseCoffee Coffee
}

func (cd *CapuccinoDecorator) GetPrice() float64 {
	basePrice := cd.baseCoffee.GetPrice()
	return basePrice + 7
}

func (cd *CapuccinoDecorator) GetClient() string {
	return cd.baseCoffee.GetClient()
}

func addCapuccino(base Coffee) *CapuccinoDecorator {
	return &CapuccinoDecorator{base}
}
