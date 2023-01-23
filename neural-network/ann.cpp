#include "ann.h"

#include <algorithm>
#include <random>
#include <cmath>

namespace ann {
	NeuralNetwork::NeuralNetwork(std::initializer_list<size_t> layerNeuronCounts) {
		for (auto& count : layerNeuronCounts) {
			layers.push_back(Layer(count));
		}
	}

	void NeuralNetwork::fit(size_t epochs) {

	}

	Layer::Layer(size_t numberOfNeurons) {
		std::normal_distribution<double_t> weights(0.0, std::sqrt(2.0));
		std::default_random_engine weightGenerator;

		for (size_t i = 0; i < numberOfNeurons; i++) {
			double_t weight = weights(weightGenerator);
			neurons.push_back(Neuron(weight));
		}

		bias = weights(weightGenerator);
	}

	Neuron::Neuron(double_t weight_) : weight(weight_) {
		output = 0.0;
	}

	double_t Neuron::relu(double_t input) {
		return std::max(0.0, input);
	}

	double_t Neuron::calculateOutput(std::vector<Neuron>& inputs, double_t bias) {
		for (auto& input : inputs) {
			output += input.weight * input.output;
		}
		output += bias;
		output = relu(output);
	}
}