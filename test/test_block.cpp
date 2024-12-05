#include "Block.h"
#include <cassert>

void testBlock() {
    Block block(1, "Test Data", "0");
    std::string initialHash = block.hash;
    block.mineBlock(2);

    assert(block.hash != initialHash);
    assert(block.hash.substr(0, 2) == "00");
}

int main() {
    testBlock();
    std::cout << "Block tests passed!" << std::endl;
    return 0;
}
