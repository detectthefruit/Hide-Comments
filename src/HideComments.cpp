#include <Geode/Bindings.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/binding/GameManager.hpp>

using namespace geode::prelude;

static bool isBlockedComment(GJComment* comment) {
    if (!comment || comment->m_accountID <= 0) {
        return false;
    }

    auto manager = GameManager::sharedState();
    if (!manager) {
        return false;
    }

    return manager->isPlayerBlocked(comment->m_accountID);
}

struct $modify(CommentCell) {
    void loadFromComment(GJComment* comment) {
        CommentCell::loadFromComment(comment);

        if (!Mod::get()->getSettingValue<bool>("hideBlockedComments")) {
            return;
        }

        if (isBlockedComment(comment)) {
            this->setVisible(false);
        }
    }
};
