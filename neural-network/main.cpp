#include <iostream>

#include "ann.h"

int main() {
	auto layer = ann::Layer(6);
	layer.printBias();
	layer.printWeights();
	return 0;
}
