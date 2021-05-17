//
// Created by ariel on 5/17/21.
//

#include "database.h"


Database::Database(std::string database_file_path): database_file_path_(database_file_path) {
    if (!LoadDatabase()) {
        std::cout << "failed to load database..." << std::endl;
    }
    std::cout << "database was successfully loaded" << std::endl;
}
Database::~Database() {
    // write map to file, exit gracefully
}
bool Database::UpdateValue(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(database_lock_);
    auto it = database_.find(key);
    if (it != database_.end()) {
        it->second = value;
        return true;
    }
    return false;
}

bool Database::InsertEntry(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(database_lock_);
    auto it = database_.find(key);
    if (it != database_.end()) {
        return false; // already inside
    }
    database_.insert({key, value});
    return true;
}

bool Database::DeleteEntry(const std::string& key) {
    std::lock_guard<std::mutex> lock(database_lock_);
    database_.erase(key);
}

bool Database::ClearDatabase() {
    std::lock_guard<std::mutex> lock(database_lock_);
    database_.clear()
}

bool Database::GetValue(const std::string& key, std::string& value) {
    std::lock_guard<std::mutex> lock(database_lock_);
    auto it = database_.find(key);
    if (it != database_.end()) {
        value = it->second;
        return true;
    }
    return false;
}

bool Database::LoadDatabase() {

}