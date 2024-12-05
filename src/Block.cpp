#include "Block.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <openssl/sha.h>

Block::Block(int idx, const std::string &info, const std::string &prevHash)
    :   index(idx), data(info), previousHash(prevHash), nonce(0){
        timestamp = std::to_string(time(nullptr));
        hash = calculateHash();
}

std::string Block::calculateHash(){
    std::stringstream ss;
    ss << index << timestamp << data << previousHash << nonce;
    return sha256(ss.str()); 
}

void Block::mineBlock(int difficulty){
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
}

std::string Block::sha256(const std::string &str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)str.c_str(), str.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}