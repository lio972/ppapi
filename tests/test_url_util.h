// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_TESTS_TEST_URL_UTIL_H_
#define PPAPI_TESTS_TEST_URL_UTIL_H_

#include "ppapi/cpp/url_util.h"
#include "ppapi/tests/test_case.h"

class TestUrlUtil : public TestCase {
 public:
  TestUrlUtil(TestInstance* instance) : TestCase(instance), util_(NULL) {}

  // TestCase implementation.
  virtual bool Init();
  virtual void RunTest();

 private:
  std::string TestCanonicalize();
  std::string TestResolveRelative();
  std::string TestIsSameSecurityOrigin();
  std::string TestDocumentCanRequest();
  std::string TestDocumentCanAccessDocument();

  pp::UrlUtil* util_;
};

#endif  // PPAPI_TESTS_TEST_URL_UTIL_H_
