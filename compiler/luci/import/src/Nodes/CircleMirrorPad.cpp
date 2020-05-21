/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "luci/Import/Nodes/CircleMirrorPad.h"

#include <luci/IR/Nodes/CircleMirrorPad.h>

#include <loco.h>

namespace luci
{

bool CircleMirrorPadGraphBuilder::validate(const ValidateArgs &args) const
{
  if (args.op.inputs.size() != 2)
    return false;

  // TODO check others

  return true;
}

CircleNode *CircleMirrorPadGraphBuilder::build_node(const circle::OperatorT &op,
                                                    const std::vector<CircleNode *> &inputs,
                                                    loco::Graph *graph) const
{
  auto *node = graph->nodes()->create<CircleMirrorPad>();
  node->input(inputs[0]);
  node->paddings(inputs[1]);

  const auto *options = op.builtin_options.AsMirrorPadOptions();
  node->mode(luci_mirrorpad_mode(options->mode));

  return node;
}

} // namespace luci