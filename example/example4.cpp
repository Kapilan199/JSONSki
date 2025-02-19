#include "../src/RecordLoader.h"
#include "../src/QueryProcessor.h"

int main() {
    char* file_path = "../dataset/bestbuy_sample_small_records.json";
    RecordSet* record_set = RecordLoader::loadRecords(file_path);
    if (record_set->size() == 0) {
        cout<<"record loading fails."<<endl;
        return -1;
    }

    QueryProcessor processor("$.categoryPath[0].name");
    int num_recs = record_set->size();
    for (int i = 0; i < num_recs; i++) {
        string output = processor.runQuery((*record_set)[i]);
        cout<<"matches are: "<<output<<endl;
    }
    return 0;
}
