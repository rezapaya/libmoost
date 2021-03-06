/* vim:set ts=3 sw=3 sts=3 et: */
/**
 * Copyright © 2008-2013 Last.fm Limited
 *
 * This file is part of libmoost.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MOOST_DIGEST_SHA2_H__
#define MOOST_DIGEST_SHA2_H__

#include <boost/shared_ptr.hpp>

#include "base.h"

#define SHA2_CLASS_DECL_(bits)                               \
   class sha ## bits ## _impl;                               \
                                                             \
   class sha ## bits : public base                           \
   {                                                         \
   public:                                                   \
      sha ## bits();                                         \
      virtual void reset();                                  \
      virtual void add_raw(const void *data, size_t size);   \
      virtual std::string digest() const;                    \
                                                             \
   private:                                                  \
      boost::shared_ptr<sha ## bits ## _impl> m_impl;        \
   }

namespace moost { namespace digest {

SHA2_CLASS_DECL_(224);
SHA2_CLASS_DECL_(256);
SHA2_CLASS_DECL_(384);
SHA2_CLASS_DECL_(512);

}}

#undef SHA2_CLASS_DECL_

#endif
