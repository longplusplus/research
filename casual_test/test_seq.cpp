#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand ( unsigned ( std::time(0) ) );
    const char* arr[] = {
        "SofaVrIONode-sofa_video_list",
        "ForkMixSVUserCfIONode-video_user_cf",
        "ForkItemCfMixedVideoIONode-video_item_cf",
        "NewCbIONode-fork_list"
    };

    std::size_t idx[] = {0, 1, 2, 3};

    std::unordered_map<std::string, std::pair<std::size_t, std::size_t>> str2int;
    std::random_shuffle(idx, idx + 4);

    for (std::size_t i = 0; i < 4; ++i) {
        std::fprintf(stderr, "%zu ", idx[i]);
        str2int[arr[idx[i]]] = std::make_pair(idx[i], i);
    }

    std::fprintf(stderr, "\n");
    std::fprintf(stderr, "============auto iteration===================\n");
    for (auto& pair : str2int) {
        std::fprintf(stderr, "%s->(id:%zu,insert_order:%zu)\n", pair.first.c_str(), pair.second.first, pair.second.second);
    }

    
    std::fprintf(stderr, "============iterator iteration===============\n");
    for (auto iter = str2int.begin();
            iter != str2int.end();
            ++iter) {
        std::fprintf(stderr, "%s->(id:%zu,insert_order:%zu)\n", iter->first.c_str(), iter->second.first, iter->second.second);
    }

    return 0;
}
