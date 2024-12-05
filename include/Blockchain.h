#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
public:
    Blockchain();
    void addBlock(const std::string &data);
    void printChain() const;

private:
    std::vector<Block> chain;
    int difficulty;

    Block getLatestBlock() const;
};

#endif
