#include "ann.h"

namespace ann {
	NeuralNetwork::NeuralNetwork(std::initializer_list<size_t> layerNeuronCounts) {
		for (auto& count : layerNeuronCounts) {
			layers.push_back(Layer(count));
		}
	}

	void NeuralNetwork::fit(size_t epochs, std::string& trainPath) {
		std::cout << "Starting training for " << epochs << " epochs..." << std::endl;
		std::ifstream trainingSet(trainPath);
	}

	Layer::Layer(size_t numberOfNeurons, bool isInput = false) {
		if (isInput) {
			for (size_t i = 0; i < numberOfNeurons; i++) {
				neurons.push_back(Neuron(1.0));
			}
			bias = 0.0;
			return;
		}

		std::normal_distribution<double_t> weights(0.0, std::sqrt(2.0/numberOfNeurons));
		std::default_random_engine weightGenerator;

		for (size_t i = 0; i < numberOfNeurons; i++) {
			double_t weight = weights(weightGenerator);
			neurons.push_back(Neuron(weight));
		}

		bias = weights(weightGenerator);
	}

	void Layer::setInputLayer(std::vector<double_t>& inputs) {
		size_t i = 0;
		for (auto& neuron : neurons) {
			neuron.setOutput(inputs[i++]);
		}
	}

	void Layer::printBias() {
		std::cout << "Layer bias is " << bias << std::endl;
	}

	void Layer::printWeights() {
		std::cout << "Layer weights are ";
		for (auto& neuron : neurons) {
			std::cout << neuron.getWeight() << " ";
		}
		std::cout << std::endl;
	}

	Neuron::Neuron(double_t weight_) : weight(weight_) {
		output = 0.0;
	}

	double_t Neuron::getWeight() {
		return weight;
	}

	double_t Neuron::relu(double_t input) {
		return std::max(0.0, input);
	}

	void Neuron::setOutput(double_t output_) {
		output = output_;
	}

	void Neuron::calculateOutput(std::vector<Neuron>& inputs, double_t bias) {
		for (auto& input : inputs) {
			output += input.weight * input.output;
		}
		output += bias;
		output = relu(output);
	}
}