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
#include <stdexcept>
#include <string_view>
#include <target_config.h>

namespace nncase
{
namespace ir
{
#define DEFINE_NEUTRAL_OPCODE(id, name, value) op_##id = value,
#define DEFINE_OPCODE(target, id, name, value) op_##target##_##id = value,

    enum node_opcode
    {
#include "opcode.def"
    };

#undef DEFINE_NEUTRAL_OPCODE
#undef DEFINE_OPCODE
#define DEFINE_NEUTRAL_OPCODE(id, name, value) \
    case op_##id:                              \
        return #name;
#define DEFINE_OPCODE(target, id, name, value) \
    case op_##target##_##id:                     \
        return #name;

    constexpr std::string_view node_opcode_names(node_opcode opcode)
    {
        switch (opcode)
        {
#include "opcode.def"
        default:
            throw std::invalid_argument("invalid opcode");
        }
    }

#undef DEFINE_NEUTRAL_OPCODE
#undef DEFINE_OPCODE
}
}
