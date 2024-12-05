#include "Block.h"
#include "Blockchain.h"
#include <iostream>

int main(){
    Blockchain blockchain;
    std::cout << "Adding blocks to the blockchain..." << std::endl;
    blockchain.addBlock("Block 1 Data");
    blockchain.addBlock("Block 2 Data");
    
    std::cout << "Blockchain contents:" << std::endl;

    blockchain.printChain();

    return 0;
}