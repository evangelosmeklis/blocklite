#include "Blockchain.h"
#include <cassert>
#include <iostream>

void testGenesisBlock() {
    Blockchain blockchain;
    std::cout << "Testing Genesis Block..." << std::endl;

    // Check that the chain has one block initially
    assert(blockchain.getChain().size() == 1);

    // Check the genesis block's data
    Block genesis = blockchain.getChain().front();
    assert(genesis.index == 0);
    assert(genesis.previousHash == "0");
    std::cout << "Genesis block tests passed!" << std::endl;
}

void testAddBlock() {
    Blockchain blockchain;
    std::cout << "Testing Adding Blocks..." << std::endl;

    blockchain.addBlock("Block 1 Data");
    blockchain.addBlock("Block 2 Data");

    // Check that the chain has 3 blocks (including genesis)
    assert(blockchain.getChain().size() == 3);

    // Verify the second block's data and linkage
    Block secondBlock = blockchain.getChain()[1];
    assert(secondBlock.data == "Block 1 Data");
    assert(secondBlock.index == 1);
    assert(secondBlock.previousHash == blockchain.getChain()[0].hash);

    // Verify the third block's data and linkage
    Block thirdBlock = blockchain.getChain()[2];
    assert(thirdBlock.data == "Block 2 Data");
    assert(thirdBlock.index == 2);
    assert(thirdBlock.previousHash == blockchain.getChain()[1].hash);

    std::cout << "Adding blocks tests passed!" << std::endl;
}

void testMiningDifficulty() {
    Blockchain blockchain;
    std::cout << "Testing Mining Difficulty..." << std::endl;

    blockchain.addBlock("Block with difficulty");
    Block minedBlock = blockchain.getChain().back();

    // Verify the hash satisfies the difficulty
    std::string target(blockchain.getDifficulty(), '0');
    assert(minedBlock.hash.substr(0, blockchain.getDifficulty()) == target);

    std::cout << "Mining difficulty test passed!" << std::endl;
}

int main() {
    testGenesisBlock();
    testAddBlock();
    testMiningDifficulty();

    std::cout << "All Blockchain tests passed!" << std::endl;
    return 0;
}
