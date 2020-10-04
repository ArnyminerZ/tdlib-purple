#include "identifiers.h"
#include <glib.h>

const UserId       UserId::invalid       = UserId(0);
const ChatId       ChatId::invalid       = ChatId(0);
const BasicGroupId BasicGroupId::invalid = BasicGroupId(0);
const SupergroupId SupergroupId::invalid = SupergroupId(0);
const SecretChatId SecretChatId::invalid = SecretChatId(0);

UserId getId(const td::td_api::user &user)
{
    return UserId(user.id_);
}

ChatId getId(const td::td_api::chat &chat)
{
    return ChatId(chat.id_);
}

BasicGroupId getId(const td::td_api::basicGroup &group)
{
    return BasicGroupId(group.id_);
}

SupergroupId getId(const td::td_api::supergroup &group)
{
    return SupergroupId(group.id_);
}

SecretChatId getId(const td::td_api::secretChat &secretChat)
{
    return SecretChatId(secretChat.id_);
}

UserId getUserId(const td::td_api::chatTypePrivate &privType)
{
    return UserId(privType.user_id_);
}

UserId getUserId(const td::td_api::chatMember &member)
{
    return UserId(member.user_id_);
}

UserId getUserId(const td::td_api::call &call)
{
    return UserId(call.user_id_);
}

UserId getSenderUserId(const td::td_api::message &message)
{
    return UserId(message.sender_user_id_);
}

UserId getSenderUserId(const td::td_api::messageForwardOriginUser &forwardOrigin)
{
    return UserId(forwardOrigin.sender_user_id_);
}

UserId getUserId(const td::td_api::secretChat &secretChat)
{
    return UserId(secretChat.user_id_);
}

UserId getUserId(const td::td_api::updateUserStatus &update)
{
    return UserId(update.user_id_);
}

UserId getUserId(const td::td_api::updateUserChatAction &update)
{
    return UserId(update.user_id_);
}

UserId getUserId(const td::td_api::importedContacts &contacts, unsigned index)
{
    return UserId(contacts.user_ids_[index]);
}

UserId getUserId(const td::td_api::users &users, unsigned index)
{
    return UserId(users.user_ids_[index]);
}

UserId stringToUserId(const char *s)
{
    const char *c = s;
    if (*c == '-')
        c++;
    if ((*c == '\0') || (*c == '0'))
        return UserId::invalid;
    for (; *c; c++)
        if ((c >= s+12) || !isdigit(*c))
            return UserId::invalid;

    long long x;
    static_assert(sizeof(x) > 4, "need more than int32 here");
    x = atoll(s);
    if ((x < INT32_MIN) || (x > INT32_MAX))
        return UserId::invalid;

    return UserId(x);
}

ChatId getChatId(const td::td_api::updateChatChatList &update)
{
    return ChatId(update.chat_id_);
}

ChatId getChatId(const td::td_api::updateChatOrder &update)
{
    return ChatId(update.chat_id_);
}

ChatId getChatId(const td::td_api::updateChatTitle &update)
{
    return ChatId(update.chat_id_);
}

ChatId getChatId(const td::td_api::messageForwardOriginChannel &forwardOrigin)
{
    return ChatId(forwardOrigin.chat_id_);
}

ChatId getChatId(const td::td_api::message &message)
{
    return ChatId(message.chat_id_);
}

ChatId getChatId(const td::td_api::updateUserChatAction &update)
{
    return ChatId(update.chat_id_);
}

ChatId stringToChatId(const char* s)
{
    int64_t id;
    if (sscanf(s, "%" G_GINT64_FORMAT "", &id) == 1)
        return ChatId(id);
    return ChatId::invalid;
}

BasicGroupId getBasicGroupId(const td::td_api::updateBasicGroupFullInfo &update)
{
    return BasicGroupId(update.basic_group_id_);
}

BasicGroupId getBasicGroupId(const td::td_api::chatTypeBasicGroup &update)
{
    return BasicGroupId(update.basic_group_id_);
}

SupergroupId getSupergroupId(const td::td_api::updateSupergroupFullInfo &update)
{
    return SupergroupId(update.supergroup_id_);
}

SupergroupId getSupergroupId(const td::td_api::chatTypeSupergroup &update)
{
    return SupergroupId(update.supergroup_id_);
}