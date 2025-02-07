/* Copyright 2019 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once 
#include <memory>
#include <ir/graph.h>
#include <filesystem>

namespace nncase
{
namespace importer
{
    ir::graph import_tflite(xtl::span<const uint8_t> model);
    ir::graph import_paddle(xtl::span<const uint8_t> model, const std::filesystem::path& params_dir);
}
}
