/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __MODEL_H__
#define __MODEL_H__

#include <mio/tflite/schema_generated.h>

#include <memory>

namespace tflinspect
{

struct Model
{
  virtual ~Model() = default;

  virtual const ::tflite::Model *model(void) const = 0;
};

/**
 * @brief Load TensorFlow Lite model (as a raw Model) from a given path
 *
 * @note May return a nullptr
 */
std::unique_ptr<Model> load_tflite(const std::string &path);

} // namespace tflinspeat

#endif // __MODEL_H__
