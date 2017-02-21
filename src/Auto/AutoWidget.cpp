/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011-2017. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoWidget.h"
#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace frc {

/**
 * Adds the given object to the list of options.
 *
 * On the {@link SmartDashboard} on the desktop, the object will appear as the
 * given name.
 *
 * @param name   the name of the option
 * @param object the option
 */
void AutoWidget::AddObject(llvm::StringRef name, int routine) {
  SmartDashboard::PutNumber("Made it to list options", (double) routine);

  m_choices[name] = routine;
}

/**
 * Add the given object to the list of options and marks it as the default.
 *
 * Functionally, this is very close to {@link AutoWidget#AddObject(const
 * char *name, void *object) AddObject(...)} except that it will use this as
 * the default option if none other is explicitly selected.
 *
 * @param name   the name of the option
 * @param object the option
 */

void AutoWidget::AddDefault(llvm::StringRef name, int defaultRoutine) {
  SmartDashboard::PutNumber("Made it to list options", (double) defaultRoutine);

  m_defaultChoice = name;
  AddObject(name, defaultRoutine);
}

/**
 * Returns the selected option.
 *
 * If there is none selected, it will return the default.  If there is none
 * selected and no default, then it will return {@code nullptr}.
 *
 * @return the option selected
 */
int AutoWidget::GetSelected() {
  std::string selected = m_table->GetString(kSelected, m_defaultChoice);
  if (selected == "") {
    return 0;
  } else {
    return m_choices[selected];
  }
}

void AutoWidget::InitTable(std::shared_ptr<ITable> subtable) {
  std::vector<std::string> keys;
  m_table = subtable;
  if (m_table != nullptr) {
    for (const auto& choice : m_choices) {
      keys.push_back(choice.first());
    }

    // Unlike std::map, llvm::StringMap elements are not sorted
    std::sort(keys.begin(), keys.end());

    m_table->PutValue(kOptions, nt::Value::MakeStringArray(std::move(keys)));
    m_table->PutString(kDefault, m_defaultChoice);
  }
}

}  // namespace frc
