//
// Copyright 2020 the authors listed in CONTRIBUTORS.md
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef PIR_SERVER_H_
#define PIR_SERVER_H_

#include <optional>
#include <string>

#include "seal/seal.h"

namespace pir {

class PIRServer {
 public:
  // Creates and returns a new server instance.
  static std::unique_ptr<PIRServer> Create(
      const seal::EncryptionParameters& params);

  std::optional<std::string> ProcessRequest(const std::string& request) const;

  int PopulateDatabase(const std::vector<std::string>& db);

  PIRServer() = delete;

 private:
  PIRServer(const seal::EncryptionParameters& params);
};

}  // namespace pir

#endif  // PIR_SERVER_H_
