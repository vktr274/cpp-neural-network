#include <iostream>

#include "ann.h"

int main() {
	auto layer = ann::Layer(6, true);
	layer.printBias();
	layer.printWeights();
	return 0;
}
