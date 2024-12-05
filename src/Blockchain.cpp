#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    difficulty = 4; // Number of leading zeros in hash
    chain.emplace_back(Block(0, "Genesis Block", "0"));
}

void Blockchain::addBlock(const std::string &data) {
    Block newBlock(chain.size(), data, chain.back().hash);
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

void Blockchain::printChain() const {
    for (const auto &block : chain) {
        std::cout << "Block " << block.index << ":\n";
        std::cout << "  Data: " << block.data << "\n";
        std::cout << "  Hash: " << block.hash << "\n";
        std::cout << "  Prev: " << block.previousHash << "\n\n";
    }
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}