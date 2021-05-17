//
// Created by ariel on 5/17/21.
//

#ifndef IRC_CHAT_DATABASE_H
#define IRC_CHAT_DATABASE_H

#include <string>
#include <unordered_map>
#include <iosteram>
#include <mutex>

// TODO: consider using some postgres DB
// We will use string->string mapping, and will cast when relevant
// This is not an ACID DB, just a simple storage-like mechanism
// This is a thread-safe DB, but not optimised for performance (yet)
class Database {
public:
    Database(std::string database_file_path);
    virtual ~Database();
    virtual bool UpdateValue(const std::string& key, const std::string& value);
    virtual bool DeleteEntry(const std::string& key);
    virtual bool ClearDatabase();
    virtual vool GetValue(const std::string& key, std::string& value) const;
private:
    virtual bool LoadDatabase();
    std::string database_file_path_;
    std::unordered_map<std::string, std::string> database_;
    std::mutex database_lock_;
};


#endif //IRC_CHAT_DATABASE_H
