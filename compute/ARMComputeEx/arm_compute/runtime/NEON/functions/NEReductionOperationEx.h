/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright (c) 2017-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARM_COMPUTE_NEREDUCTIONOPERATIONEX_H__
#define __ARM_COMPUTE_NEREDUCTIONOPERATIONEX_H__

#include "arm_compute/runtime/IFunction.h"

#include "arm_compute/core/NEON/kernels/NEFillBorderKernel.h"
#include "arm_compute/core/NEON/kernels/NEReductionOperationKernelEx.h"
#include "arm_compute/core/TypesEx.h"

namespace arm_compute
{
class ITensor;

/** Basic function to simulate a reduction operation. This function calls the following NEON
 * kernels:
 *
 * -# @ref NEFillBorderKernel
 * -# @ref NEReductionOperationKernelEx
 *
 */
class NEReductionOperationEx : public IFunction
{
public:
  /** Default constructor */
  NEReductionOperationEx();
  /** Set the input and output tensors.
   *
   * @param[in]  input  Source tensor. Data type supported: QASYMM8/F16/F32.
   * @param[out] output Destination tensor. Data types and data layouts supported: same as @p input.
   * @param[in]  axis   Dimension along which to reduce.
   * @param[in]  op     Reduction operation to perform.
   */
  void configure(ITensor *input, ITensor *output, unsigned int axis, ReduceOperation op);

  /** Static function to check if given info will lead to a valid configuration of @ref
   * NEReductionOperationEx.
   *
   * @param[in] input  Source tensor info. Data type supported: QASYMM8/F16/F32.
   * @param[in] output Destination tensor info. Data types and data layouts supported: same as @p
   * input.
   * @param[in] axis   Dimension along which to reduce.
   * @param[in] op     Reduction operation to perform.
   *
   * @return a status
   */
  static Status validate(const ITensorInfo *input, const ITensorInfo *output, unsigned int axis,
                         ReduceOperation op);

  // Inherited methods overridden:
  void run() override;

private:
  NEReductionOperationKernelEx _reduction_kernel;
  NEFillBorderKernel _fill_border_kernel;
  size_t _window_split;
  int _reduction_axis;
};
} // namespace arm_compute
#endif /* __ARM_COMPUTE_NEREDUCTIONOPERATIONEX_H__ */
