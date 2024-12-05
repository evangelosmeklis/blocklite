#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
    public:
        Block(int idx, const std::string &info, const std::string &prevHash);

        std::string calculateHash();
        void mineBlock(int difficulty);

        int index;
        std::string timestamp;
        std::string data;
        std::string previousHash;
        std::string hash;
    
    private:
        int nonce;
        std::string sha256(const std::string &str);
};

#endif  // BLOCK_H